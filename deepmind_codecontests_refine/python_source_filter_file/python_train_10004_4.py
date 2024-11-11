n,k = map(int,input().split())
s = input()
a = (n-k)//2
print(a)
s1 = s.replace('(','',a)
s2 = s1.replace(')','',a)
print(s2)