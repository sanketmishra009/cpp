x, y = input().split()
x = x*int(y) % 9


def supernum(n):
    if len(n) == 1:
        return n

    else:
        sum = 0
        for i in n:
            sum = sum + int(i)
        return supernum(str(sum))


print(x if x else 9)
