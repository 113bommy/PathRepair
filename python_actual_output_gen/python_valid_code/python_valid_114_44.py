s=input()
w=int(input())
ans=""
for i in range(-len(s)//-w):
    ans+=s[i*w]
print(ans)
