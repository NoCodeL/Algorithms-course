% Akash Deep; 13119008; Assignment 4; Convex Hull Algorithms
% performance comparison are reported in "Assignment_4.pdf"
clc;
clear all;
close all;
global XY N XY_GS
n = [100,1000, 2000, 5000, 10000];
avg_time = zeros(5,3);
for n_i = 1:5
    N = n(n_i);
    XY = N*rand(N,2);
    %plot (XY(:,1), XY(:,2), 'b.', 'MarkerSize', 20 );
    data = zeros(3,3);

    for iter = 1:3
        %% Gift wrapping algorithm
        tic
        GWhull=GW();
        %hold on
        %plot( XY(GWhull,1), XY(GWhull,2), 'r-', 'LineWidth', 2 );
        data(iter,1) = toc;
        %% Graham scan algorithm
        tic
        GShull=GS();
        % hold on
        % plot( XY_GS(GShull,1), XY_GS(GShull,2), 'r-', 'LineWidth', 2 );
        data(iter,2) = toc;
        %% Quickhull
        tic
        Qhull=Q();
        % hold on
        % plot( XY(Qhull,1), XY(Qhull,2), 'r-', 'LineWidth', 2 );
        data(iter,3) = toc;
    end
    avg_time(n_i,:) = mean(data);
    %% 
end
%xlswrite(avg_time, 'Assign4.xlsx');
plot(avg_time(:,1),'b.-', 'MarkerSize', 20)
hold on
plot(avg_time(:,2),'g.-', 'MarkerSize', 20)
hold on
plot(avg_time(:,3),'r.-', 'MarkerSize', 20)
hold off