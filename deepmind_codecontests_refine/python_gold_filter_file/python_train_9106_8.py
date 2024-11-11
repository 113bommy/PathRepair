s=input()
n=int(input())
k=len(s)//n
if(s[:k]==s[k-1::-1] and (not len(s)%n)):
    print("YES" if all(s[i:i+k]==s[i+k-1:i-1:-1] for i in range(k,len(s),k)) else "NO")
else:
    print("NO")