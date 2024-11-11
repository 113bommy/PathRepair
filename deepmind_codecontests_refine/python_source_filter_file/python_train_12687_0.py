cnt=0
sell_num=0
total=0

while True:
    try:
        t,s=map(int,input().split(","))
    except:
        break
    cnt+=1
    sell_num+=s
    total+=t*s
print(total)
print(round(sell_num/cnt))