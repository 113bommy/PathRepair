n=int(input())
s=input()
print(max(len(set(s[0:m])&set(s[m:n]))for m in range(n)))