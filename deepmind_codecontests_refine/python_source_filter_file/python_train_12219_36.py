n=int(input())
nums=list(map(int,input().split()))
chest=0
biceps=0
back=0
for i in range(1,len(nums)+1):
    if i%3==1:
        chest=chest+nums[i-1]
    elif i%3==2:
        biceps=biceps+nums[i-1]
    elif i%3==0:
        back=back+nums[i-1]
if chest>biceps and chest>back:
    print("chest")
elif biceps>chest and biceps>chest:
    print("biceps")
elif back>chest and back>biceps:
    print("back")