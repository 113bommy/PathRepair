

T = int(input())

for t in range(T):
    n, m = tuple([int(x) for x in input().split()])
    ss = []
    for i in range(n):
        ss.append(input().strip())

    # We only need to consider first 3 node in ss
    
    # Special case when n == 2
    if n == 2:
        if ss[0][1] != ss[1][0] and m % 2 == 0:
            print("NO")
        else:
            print("YES")
            print(" ".join([str((i%2)+1) for i in range(m+1)]))
    else:
        # There is always a solution!
        print("YES")

        # Check if there is two node that have same label going and back
        two_nodes = None
        for i in range(n):
            for j in range(i+1, n):
                if ss[i][j] == ss[j][i]:
                    two_nodes = (i, j)
                    break
            if two_nodes is not None:
                break
        if two_nodes is not None:
            solution = [str(two_nodes[i%2]+1) for i in range(m+1)]
            print(" ".join(solution))
            continue

        # Check if there the first three nodes have always different label to other 2
        same_label_pos = []
        for i in range(3):
            if ss[i][(i+1)%3] == ss[i][(i+2)%3]:
                same_label_pos.append(i)

        if len(same_label_pos) == 0:
            solution = [str((i%3)+1) for i in range(m+1)]
            print(" ".join(solution))
            continue
        else:
            if m % 2 == 1:
                solution = [str((i%2)+1) for i in range(m+1)]
                print(" ".join(solution))
                continue
            else:
                diff_label_pos = None
                for i in range(3):
                    if i in same_label_pos:
                        continue
                    else:
                        diff_label_pos = i
                        break
                solution = [str(same_label_pos[i%2]+1) for i in range(m//2)] + [str(diff_label_pos+1)] + [str(same_label_pos[(i+((m//2)%2))%2]+1) for i in range(m//2)]
                print(" ".join(solution))
                continue







        



    
