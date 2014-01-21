bool GetCpuId(char* id, int len);

bool GetMainBoardId(char* id, int len);

bool GetBiosId(char* id, int len);

bool GetDiskId(char* id, int len);

bool GetMacAddress(char* mac, int len);


bool GetHardInfoByWMI(const char* wql, const wchar_t * prop, char* value, int len);
