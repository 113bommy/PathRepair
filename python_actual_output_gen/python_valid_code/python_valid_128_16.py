n=input()
cnt=0
for i in n:
    if i in "HQ9+":
        cnt+=1
print("YES" if cnt>0 else "NO")