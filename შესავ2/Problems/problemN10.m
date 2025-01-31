rectFilt(x,4)
function smoothed = rectFilt(x, width)
    if mod(width, 2) == 0
        disp('width should be odd');
        width = width+1;
    end
    smoothed = length(x);
    dev = (width - 1) / 2;
    k = x;
    k(1) = [];
    k(2) = [];
    k(length(k)) = [];
    k(length(k)) = [];
    y = [mean(x(1 : 2 * dev)), mean(x(2 : 2 + dev)), k ,mean(x(smoothed - 1 - dev : smoothed - 1)), mean(x(smoothed - dev : smoothed))];
    for o = (1 + dev):(smoothed - dev)
        y(o) = mean(x((o - dev):(o + dev)));
    end
    
    plot(1:smoothed, x,'o','MarkerFaceColor', 'b');
    hold on
    plot(1:smoothed, y, 'r');
end