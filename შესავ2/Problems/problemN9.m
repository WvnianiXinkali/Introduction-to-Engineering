loopTest(15)

function loopTest(N)
    for p = 1:N
        if mod(p, 3) == 0 && mod(p, 2) == 0
            j = [num2str(p), ' is divisable by 2 AND 3'];
            disp(j);
        elseif mod(p, 3) == 0
            j = [num2str(p), ' is divisable by 3'];
            disp(j);
        elseif mod(p, 2) == 0
            j = [num2str(p), ' is divisable by 2'];
            disp(j);
        else
            j = [num2str(p), ' is NOT divisable by 2 or 3'];
            disp(j);
        end
    end
end