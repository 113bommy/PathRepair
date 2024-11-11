def Add(ele, List):
    N = len(List)
    L, R = 0, N-1
    mid = (L+R)//2
    
    while(L <= R):
        if List[mid] > ele:
            if mid-1 >= 0:
                if List[mid-1] < ele:
                    List[mid-1] = ele
    
n = int(input())
List = [0 for i in range(n-1)]
curr_max = n
arr = list(map(int, input().split()))
L = n-1
l = len(List)
prev=False
for num in arr:
    # print(curr_max, l)
    if num == curr_max:
        # s = ''
        # s += str(num)+' '
        print(num, end=" ")
        while(l>0 and List[-1] != 0):
            # s += str(List.pop())+ ' '
            # L -= 1
            print(List.pop(), end=" ")
            prev=True
            l -= 1
        if l>0:List.pop()
        l -= 1
        # print(s)
        curr_max = l+1
    else:
        List[num-1] = num
        if prev:
            print()
        print()
        prev=False