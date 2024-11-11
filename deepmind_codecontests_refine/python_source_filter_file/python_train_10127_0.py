t = int(input());
for test in range(t):
    n = int(input().split(" ")[0])
    arr = [int(i) for i in input().split(" ")];
    if n < 3: 
        print(max(arr));
        continue;
    total = 0;
    low = float('inf');
    high = arr[0];
    mode = -1;
    for i in range(1, n):
        if arr[i] > arr[i-1]:
            if mode == 0: total -= low;
            mode = 1;
            high = arr[i];
        elif arr[i] < arr[i-1]:
            if mode == 1: total += high;
            mode = 0
            low = arr[i];

    if mode == 1: total += high;
    print(total);
