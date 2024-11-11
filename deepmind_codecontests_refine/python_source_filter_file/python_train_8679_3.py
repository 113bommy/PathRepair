def main():
    n = int(input())
    arr = list(map(int, input().split()))
    min = arr[-1]
    for j in range(arr[-1], max(arr)+2):
        if j not in arr:
            print(j)
            break
    
main()
