
flags_atob=input()
first=input()
second=input()
n=len(flags_atob)

def isTrue(flags,first_pattern,last_pattern):
    try:
        first_index_first=flags.index(first_pattern)
        second_index_last=n-1-flags[::-1].index(last_pattern[::-1])
        if first_index_first+len(first_pattern)-1<second_index_last-len(last_pattern)+1:
            return True
    except:
        pass
    return False
    

forward=isTrue(flags_atob,first,second)
backward=isTrue(flags_atob[::-1],first,second)

if forward and backward:
    print('both')
elif forward:
    print('forward')
elif backward:
    print('backard')
else:
    print('fantasy')
