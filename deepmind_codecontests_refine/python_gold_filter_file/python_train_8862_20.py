num_student = int(input())
skills_student = sorted(input().split(), key=int)

def count(array, i, j):
    return int(array[j])-int(array[i])

def team(array):
    i=0
    j=0
    max_ = 1
    count_= 1
    while j+1 < len(array):
        if count(array, i, j+1) <=5:
            j+=1
            count_+=1
        else:
            max_ = max(max_, count_)
            if count_ > 1:
                count_-=1
            i+=1
            if i > j:
                j = i
    
    max_ = max(max_, (j-i)+1)
    return max_


print(team(skills_student))
