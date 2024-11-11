import string
enumerated_alphabet= [(num,alpha) for num,alpha in enumerate(string.ascii_lowercase)]

alpha_dict={}


for each in enumerated_alphabet:
    alpha_dict[each[1]]=each[0]


def  count_rotation(string,initial='a'):
    count = 0
    if string=='':
        return 0
    current=string[0]
    distance=abs(alpha_dict[current]-alpha_dict[initial])
    if distance>=13:
        return (26-distance) +count_rotation(string[1:],current)
    else:
        return distance +count_rotation(string[1:],current)

count_rotation(input())