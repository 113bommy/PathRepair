#!/usr/bin/python

import sys
            
    
def solve(N, M, A):
    """
    A_list = []
    for A in A_list_old:
        if A not in A_list:
            A_list.append(A)
    """
    #lets see if A[0] works
    A0 = A[0]
    diff_list = []
    for i in range(1, N):
        diff = 0
        my_list = A[i]
        for j in range(M):
            if my_list[j] != A0[j]:
                diff += 1
        diff_list.append(diff)
    my_max = max(diff_list)
    if my_max < 3:
        print("Yes")
        A0 = [str(x) for x in A0]
        print(" ".join(A0))
        return
    if my_max > 4:
        print("No")
        return
    if my_max >= 3:
        my_max = max(diff_list)
        for i in range(N-1):
            if diff_list[i] == my_max:
                idx = i+1
                break
    Ax = A[idx]
    where_diff = []
    for j in range(M):
        if A0[j] != Ax[j]:
            where_diff.append(j)
    new_A = []
    diff_list = [0] + diff_list
    small_diff_list = []
    for i in range(N):
        my_list = []
        small_diff = 0
        for j in where_diff:
            small_diff += (A[i][j] != A0[j])
            my_list.append(A[i][j])
        small_diff_list.append(small_diff)
        new_A.append(my_list)  
    outside_diff_list = [diff_list[i] - small_diff_list[i] for i in range(N)]
    if my_max == 3:
        for k1 in range(3):
            for k2 in range(3):
                if k1 != k2:
                    k3 = 3 - k1 - k2
                    keep_from_A0 = where_diff[k1]
                    keep_from_Ax = where_diff[k2]
                    new_diff_list = []
                    for i in range(N):
                        new_diff_list.append((A0[keep_from_A0] != A[i][keep_from_A0]) + (Ax[keep_from_Ax] != A[i][keep_from_Ax]))
                    merged_diff_list = [new_diff_list[i] + outside_diff_list[i] for i in range(N)]
                    if max(merged_diff_list) < 2:
                        print("Yes")
                        common_seq = [x for x in A0]
                        common_seq[keep_from_Ax] = Ax[keep_from_Ax]
                        common_seq[where_diff[k3]] = 1
                        print(" ".join([str(x) for x in common_seq]))
                        return
                    elif max(merged_diff_list) == 2:
                        lehet_jo = True
                        values = -1
                        for i in range(N):
                            if merged_diff_list[i] == 2:
                                if values < 0:
                                    values = A[i][where_diff[k3]]
                                else:
                                    if values != A[i][where_diff[k3]]:
                                        lehet_jo = False
                        if lehet_jo:
                            print("Yes")
                            #a sorozatot kene kiirni csak
                            common_seq = [x for x in A0]
                            common_seq[keep_from_Ax] = Ax[keep_from_Ax]
                            common_seq[where_diff[k3]] = values
                            print(" ".join([str(x) for x in common_seq]))
                            return
    if my_max == 4:
        #we can take 0,1 0,2 0,3 1,2 1,3 or 2,3 from A0, other two from Ax
        idx_tuples = [(0,1), (0,2), (0,3), (1,2), (1,3), (2,3)]
        for idx_tuple in idx_tuples:
            vals = [A0[where_diff[i]] if i in idx_tuple else Ax[where_diff[i]] for i in range(4)]
            new_diff_list = []
            for i in range(N):
                diff = 0
                for j in range(4):
                    if new_A[i][j] != vals[j]: 
                        diff += 1
                new_diff_list.append(diff)
            merged_diff_list = [new_diff_list[i] + outside_diff_list[i] for i in range(N)]
            if max(merged_diff_list) <= 2:
                print("Yes")
                common_seq = [x for x in A0]
                for ii in range(4):
                    common_seq[where_diff[ii]] = vals[ii]
                print(" ".join([str(x) for x in common_seq]))
                return
    print("No")
    return
                
                
                        
                        
                        
    
    
    
def run():
    out = ""    
    N, M = [int(x) for x in input().split()]
    A_list = []
    for i in range(N):
        A = [int(x) for x in input().split()]
        A_list.append(A)
    (solve(N, M, A_list))

run()
