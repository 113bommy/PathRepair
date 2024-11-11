def div(str_: str):
    for a in str_:
        if str_.count(a) > len(str_)/2:
            return False
    return True


def div_(str_: str):
    for i in range(len(str_)):
        for j in range(i+1, len(str_)+1):
            if div(str_[i:j]):
                return str_[i:j]
    return None


if __name__ == "__main__":
    input()
    str_ = div_(input())
    if str_ is None:
        print("NO")
    else:
        print("YES\n%s" % str_)
