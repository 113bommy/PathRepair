"""write your code in method solve"""
def solve():

    n=int(input())
    str_a=input()
    str_a.strip(' ')
    list_a=str_a.split(' ')
    list_b=[int(i) for i in list_a]

    sum_a=0
    sum_b=0
    i=0
    a=0
    b=0

    sum_a=sum(list_b)

    for i in range(n):
        sum_b+=list_b[i]
        if sum_b>sum_a/2:
            break

    if(sum(list_b[0:i])<sum(list_b[i+1:n])):
        a=i+1
        b=n-i-1
    else:
        a=i
        b=n-i

    print(a,b)

    return


if __name__=="__main__":
    solve()
