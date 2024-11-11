
def result():
    ele = list(map(int,input().split()))
    string = input()
    zero = string .count('0')
    one = string .count('1')
    print(zero,one)
    difference = abs(ele[1]-ele[2])
    if difference>ele[3]:
        if ele[1]>ele[2]:
            print((ele[0])*ele[2] + zero*ele[3])
        else:
            print((ele[0])*ele[1] + one*ele[3])
    else:
        total = zero*ele[1] + one * ele[2]
        print(total)
    
for i in range(int(input())):
    result()
    