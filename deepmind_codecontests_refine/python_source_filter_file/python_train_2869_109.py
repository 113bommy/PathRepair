from string import ascii_lowercase

low = list(ascii_lowercase)
user_low = []

user_input = input()


def convert(list):
    s = [str(i) for i in list]

    res = ("".join(s))

    return res

for num in range(0,int(user_input)):
    count = 0
    user_speling = input()
    user_speling = list(user_speling)

    if len(user_speling) >= 10:
        for check in range(1, len(user_speling)-1):
            for check1 in low:
                if user_speling[check] == check1 :
                    count += 1

        print(user_speling[0]+str(count)+user_speling[int(len(user_speling))-1])

    else:
        print(convert(user_speling))







