n=int(input())
s=input()
if len(s)>26: print(-1)
else: print(n-len((set(s))))