if __name__ == "__main__":
    t = int(input())
    while t>0:
        t-=1
        n = int(input())
        arr = list(map(int, input().split(' ')))
        # print(arr)
        idx = 0
        prev = arr[0]
        ans = []
        if prev == 1:
            ans.append(prev)
        else:
            while idx<len(arr) and arr[idx]==0:
                idx+=1
        if idx == len(arr):
            print(0)
            continue
        for i in range(idx, len(arr)):
            if arr[i] != prev:
                ans.append(arr[i])
                prev = arr[i]
            elif arr[i]==0:
                ans.append(arr[i])
        zeros = 0
        ans = ans[::-1]
        for i in range(len(ans)):
            if ans[i]==0:
                zeros+=1
            else:
                break
        print(ans[::-1])
        print(len([i for i in ans if i==0])- zeros)