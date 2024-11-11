from collections import deque

t = int(input())
for _ in range(t):
    n = int(input())
    arr = list(map(int,input().split()))
    ans = 0
    for i in range(1,27):
        for j in range(1,27):
            i_count,j_count = 0,0
            deq = deque()
            for x in arr:
                if x==i:
                    deq.append(x)
                    i_count += 1
                elif x==j:
                    deq.append(x)
                    j_count += 1

            i_move = i_count // 2
            left,right = 0,len(deq)-1
            left_seq, right_seq = deque(),deque()

            max_len = max(0,j_count)
            itr = 0
            while left<right and i_move>0:
                while left<right and deq[left] == j:
                    left+=1
                    j_count -= 1

                while left<right and deq[right] == j:
                    j_count -= 1
                    right -= 1

                itr += 1
                i_move -= 1
                max_len = max(2*(itr) + j_count,max_len)
                left += 1
                right -= 1
            ans =max(ans,max_len)
    print(ans)






