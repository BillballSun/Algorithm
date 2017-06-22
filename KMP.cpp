extern __cdecl int KMP(const char *search, const char *find)
{
	register size_t search_p = 0u, find_ p = 0u;
	register int i;
	while(1)
	{
		if(find[find_p]=='\0') return search_p - find_p;
		if(search[search_p]=='\0') return -1;
		if(search[search_p]==find[find_p]) search_p++, find_p++;
		else if(find_p==0) search_p++;
		else while(--find_p)
		{
			for(i = find_p-1; i>=0; i--) if(find[i]!=search[search_p-find_p+i]) break;
			if(i<0) break;
		}
	}
}
