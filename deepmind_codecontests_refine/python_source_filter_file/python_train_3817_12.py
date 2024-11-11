n=int(input())
s=input()[:n]
flag=0
b=s.count("0")

if s.count("0")==1 and len(s)==1:
	print("0")

elif str(1) in s:
    flag=1
print(flag,*[str(0) for a in range(b)],sep="")
