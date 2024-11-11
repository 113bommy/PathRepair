def PaintTheNumbers(arr):
    arr = sorted(arr)
    groups = []
    while(len(arr) != 0):
        group = [arr[0]]
        for i in range(1, len(arr)):
            if arr[i] % group[-1] == 0:
                group.append(arr[i])
        groups.append(group)
        arr = [x for x in arr if x not in set(group)]
    return len(groups)

if __name__ == "__main__":
    n = int(input())
    arr = [int(x) for x in input().split()]
    print(PaintTheNumbers(arr))