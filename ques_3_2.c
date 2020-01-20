int countRange(const int* numbers,int length,int start,int end)
{
	if(numbers == NULL)
		return 0;
	int count = 0;
	for(int i = 0;i<length;++i)
	{
		if(numbers[i] >= start && numbers[i]<=end)
			count++;
	}
	return count;
}
int getDuplication(const int* numbers,int length)
{
	if(numbers == NULL || length <= 0)
	{
		return -1;
	}

	int start = 1;
	int end = length - 1;

	while(end >= start)
	{
		int mid = ((end - start) >> 1) + start;
		int count = countRange(numbers,length,start,mid);
		if(end == mid)
		{
			if(count > 1)
			{
				return start;
			}
			else 
			{
				break;
			}
		}
		if(count > (mid-start + 1))
			end = mid;
		else 
			start = mid+1;
	}
	return -1;
}