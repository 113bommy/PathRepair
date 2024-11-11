s=input()
k=int(input())
if k>len(s):
    print("impossible")
else:
    s1=set(s)
    print(max(0,len(s1)))
    