n=int(input())
s=list(input())
zeros=s.count('z')
ones=int((n-(zeros*4))/3)
print(zeros,ones)
ans=""
for i in range(ones):
    ans+="1 "
for i in range(zeros):
    ans+="0 "
print(ans)
