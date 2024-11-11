list_ = list(map(int,input().split()))

'''
def tables(list_):
    if list_.count(0) == 3:
        return 0
    else:
        if list_.count(0) == 2 or sum(list_) <3:
            return 0
        else:
            if sum(list_) == 3:
                return 1
            else:
                if list_.count(0) == 1 :
                    index_0 = list_.index(0)
                    if index_0 == 0 :
                        return max(1 + tables([0,list_[1]-2,list_[2]-1]), 1+ tables([0,list_[1]-1,list_[2]-2]))
                    if index_0 == 1 :
                        return max(1 + tables([list_[0]-2,0,list_[2]-1]), 1+ tables([list_[0]-1,0,list_[2]-2]))
                    if index_0 == 2:
                        return max(1 + tables([list_[0]-2,list_[1]-1,0]), 1+ tables([list_[0]-1,list_[1]-2,0]))
                else:
                    return max(1+ tables([list_[0] -2 ,list_[1]-1,list_[2]]), 1+ tables([list_[0]-1,list_[1]-2,list_[2]]), 1+ tables([list_[0],list_[1]-2,list_[2]-1]), 1+ tables([list_[0],list_[1]-1,list_[2]-2]), 1+ tables([list_[0]-2,list_[1],list_[2]-1]),1+ tables([list_[0]-1,list_[1],list_[2]-2]))


#Turning above code into dp table: depends only on min,mid,max of triple

def tables(list_):
    min, mid, max = sorted(list_)
    if list_.count(0) == 3:
        return 0
    else:
        if list_.count(0) == 2 or sum(list_) <3:
            return 0
        else:
            if sum(list_) == 3:
                return 1
            if max > mid + 2:
                return tables([max -2, mid -1, min])
'''

sorted_list = sorted(list_)
min_, mid_, max_ = sorted_list[0], sorted_list[1], sorted_list[2]

t_1 = min_
t_2 = int(2*(mid_ - min_)/3)
t_3 = int(t_2/2) + t_1
tot_rest = (2*mid_ +min_)%3 + (max_-mid_)%3

print(t_1 + t_2 + sorted([int((max_-mid_)/3), t_3])[0] + ((2*mid_ +min_)%3 >= 1)*(max(tot_rest, max_ - t_1 - t_2 - t_3) >= 3))
