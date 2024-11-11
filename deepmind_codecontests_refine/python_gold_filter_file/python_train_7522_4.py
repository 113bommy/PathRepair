for case in range(int(input())):
    N = int(input())
    arr = list(map(int, input().split()))
    
    if N == 1:
        print(0)
    else:
        sol = []
        carry = 0
        for i in range(N):
            if carry == 0 and arr[i] < 0:
                sol.append(arr[i])
            elif carry != 0 and arr[i] < 0:
                carry += arr[i]
                if carry < 0:
                    sol.append(carry)
                    carry = 0
            elif arr[i] > 0:
                carry += arr[i]
    
        print(abs(sum(sol)))