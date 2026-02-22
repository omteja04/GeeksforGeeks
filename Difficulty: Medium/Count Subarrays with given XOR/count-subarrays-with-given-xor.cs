class Solution {
    public long subarrayXor(int[] arr, int k) {
        // code here
        Dictionary<int, int> freq = new();
        freq[0] = 1;
        long count = 0;
        int prefixXor = 0;
        foreach(var ele  in arr) {
            prefixXor ^= ele;
            int target = prefixXor ^ k;
            if(freq.TryGetValue(target, out int val)) {
                count += val;
            }
            if(freq.ContainsKey(prefixXor)) {
                freq[prefixXor]++;
            } else {
                freq[prefixXor] = 1;
            }
        }
        return count;
    }
}