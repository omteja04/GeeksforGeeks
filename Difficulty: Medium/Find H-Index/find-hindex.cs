class Solution {
    private bool Can(int[] citations, int mid)
    {
        int count = 0;
        foreach(var ele in citations)
        {
            if(ele >= mid)
            {
                count++;
            }
        }
        return count >= mid;
    }
    public int hIndex(int[] citations) {
        // code here
        int start = 1, end = citations.Length;
        
        while(start <= end)
        {
            var mid = start + (end - start) / 2;
            if(Can(citations, mid) == true)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return end;
    }
}