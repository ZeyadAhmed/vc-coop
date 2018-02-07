#pragma once
class CConfiguration
{
public:
	/* Server IP Address */
	char ServerAddress[15];

	/* Server Port */
	int ServerPort;

	/* Client Nickname */
	char Nickname[25];
	
	/* Populates values from INI file */
	void PopulateValues(char IP[15], int& Port, char Name[25]);
	
	/* Retrieves the INI reader instance */
	INIReader* GetReader() { return _inih; }

	/* Returns TRUE if config has been loaded successfully */
	bool IsConfigLoaded() { return configOpened; }

public:
	CConfiguration();
	~CConfiguration();

private:
	INIReader* _inih;
	
	bool configOpened;
	
	std::string configFilename;

	std::string sections(INIReader &reader);
};

