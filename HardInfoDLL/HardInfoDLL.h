bool GetCpuId(char* id);

bool GetMainBoardId(char* id);

bool GetBiosId(char* id);

bool GetDiskId(char* id);

bool GetMacAddress(char* mac);


bool GetHardInfoByWMI(const char* wql, const wchar_t * prop, char* value);
