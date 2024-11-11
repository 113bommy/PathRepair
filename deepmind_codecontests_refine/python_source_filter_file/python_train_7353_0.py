def main():
    n=int(input())
    arr=[int(x) for x in input().split(" ")]
    arr.sort()
    ini=0
    check=arr[0]
    flag=0
    i=0
    for i in range(1,n):
        if arr[i]!=check:
            diff=i-ini
            if diff%2!=0:
                print("Conan1")
                flag=1
                break
            ini=i
            check=arr[i]
    diff=i+1-ini
    if diff % 2 != 0 and flag==0:
        print("Conan")
        flag = 1
    if flag==0:
        print("Agasa")

main()