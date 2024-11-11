def sex_identifier(user):
    user = set(user)
    if len(user) % 2 == 0:
        return "CHAT WITH HER!"
    else:
        return "IGNORE HIM!"


def volodya(line):
    args = [int(x) for x in line.split(" ")]
    if args[0] % 2 == 0:
        if args[1] <= args[0]/2:
            return -1 + 2 * args[1]
        else:
            return 0 + 2 * (args[1] - args[0]//2)
    else:
        if args[1] <= args[0]//2 + 1:
            return -1 + 2 * args[1]
        else:
            return 0 + 2 * (args[1] - args[0]//2 - 1)

print(volodya(input()))