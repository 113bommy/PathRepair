
def mi():
	return map(int, input().split())

s = list(input())
t = input()
a = list(map(int, input().split()))

def isSubSequence(str1,str2,m,n):
    
    j = 0    # Index of str1
    i = 0    # Index of str2
    
    # Traverse both str1 and str2
    # Compare current character of str2 with 
    # first unmatched character of str1
    # If matched, then move ahead in str1
    
    while j<m and i<n:
        if str1[j] == str2[i]:    
            j = j+1    
        i = i + 1
        
    # If all characters of str1 matched, then j is equal to m
    return j==m
    
l = len(a)
high = l
low = 0
bestans = -1
while low<high:
	mid = (low+high)//2

	b = a.copy()
	s1 = s.copy()
	for i in range(mid):
		s1[b[i]-1] = ''
	
	s1 = ''.join(s1)
	if isSubSequence(t,s1,len(t),len(s1)):
		low = mid+1
		bestans = max(bestans,mid)
	else:
		high = mid-1
print (bestans)