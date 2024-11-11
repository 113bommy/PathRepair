import re


n = int(input())
for i in range(n):
    s = input()
    # check for RXCY input format
    matched = re.match('R[0-9]+C[0-9]+',s)
    # if rows are represented with digits
    if matched is not None:
        c = int(s.split('C')[1])
        r = s.split('C')[0].split('R')[1]
        res = ''
        # convert row index from letter to number
        while c>0:
            m = chr((c-1)%26+65)
            res = m + res
            c = int((c-1)/26)
        res += r
        print(res)
		
	# if rows are represented with letters
    else :
        c = 0
        res = ''
        # convert row index from number to letter 
        for j in range(len(s)):
            if s[j]>='A' and s[j]<='Z':
                c = c*26+ord(s[j])-ord('A')+1
            else :
                break
				
        res = 'R'+ s[j:]+'C'+str(c)
        print(res)