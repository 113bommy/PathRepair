n=int(input())
for i in range(n):
    index=0
    num=int(input())
    ori=(1+num)*num//2
    while 2**index<=num:
        index=index+1
    print(ori-2*(2**index-1))
