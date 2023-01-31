def func(x y)
    while x < y
    in
        x = x + 1:
        print(x)    
    end
;

def main()
    var x
    in
        while x < 10
        in
            print(x = x + 1)
        end:
        func(x-5, 12)
    end 
;
