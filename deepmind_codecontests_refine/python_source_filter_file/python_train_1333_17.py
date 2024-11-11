t=0
for i in sorted(map(int,[*open(0)]),key=lambda x:-x%10-(x%10<1)):t+=i+(10-t)%10
print(t)