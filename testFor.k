def printIf5(x)
    if x == 5 then print(x) else 0 fi
;

def allMultiplesUntil(x y)
    for i = 0, 
        i < y,
        x
    in 
        printIf5(i)
    end
;


def main() 
    allMultiplesUntil(1, 10)
;

    