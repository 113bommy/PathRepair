for _ in range(int(input())):
    arr = input()
    ln = len(arr)


    ans = []
    i = 0
    while i < ln:
        if arr[i] == 'o':
            if i+2 < ln and arr[i+1] == 'n' and arr[i+2] == 'e':
                if i - 1 > 0 and arr[i-1] == 'o':
                    ans.append(i+2)
                else:
                    ans.append(i+1)
                i += 3
                continue
        if arr[i] == 't':
            if i+2 < ln and arr[i+1] == 'w' and arr[i+2] == 'o':
                if i+3 < ln and arr[i+3] == 'n':
                    ans.append(i+3)
                elif i - 1 > 0 and arr[i-1] == 't':
                    ans.append(i+2)
                else: 
                    ans.append(i+1)
                i += 3
                continue
        i += 1
    print(len(ans))
    print(' '.join([str(x) for x in ans]))
        