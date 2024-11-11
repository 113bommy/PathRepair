from collections import Counter


freq_dict = Counter(input())
if len(freq_dict) <= 1 or len(freq_dict) > 4:
    print('No')
else:
    if len(freq_dict) == 4:
        print('Yes')
    if len(freq_dict) == 2:
        values = freq_dict.values()
        if [v for v in values if v < 2]:
            print('No')
        else:
            print('Yes')
    else:
        if sum(freq_dict.values()) == 3:
            print('No')
        else:
            print('Yes')