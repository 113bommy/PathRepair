n = int(input())
s = input()
al = [0] * 26
ans = 0
for i in range(0,len(s),2):
    if s[i] != s[i+1]: 
        j = ord(s[i+1].lower()) - ord('a')
        al[ord(s[i]) - ord('a')] += 1
        if al[j] == 1:
            al[j]-=1
        else:
            ans +=1
print(ans)