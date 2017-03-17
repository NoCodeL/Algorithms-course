% Akash Deep; 13119008; Assignment 3; Bellman Ford Algorithm
% run times are reported in "Assignment_3_Bellman-Ford.pdf"
clc;
clear all;
close all;
MAX_INT = 1.0E+5;  %infinity
%% initialize graph's V and E
% The vertices are nodes numbered 1,2,..,V (as indices)
% The edges are pair of vertices 1,2,..,E
% V = 5; 
% E = 7;
% edges = [1,3;...
%         1,4;...
%         2,1;...
%         3,4;...
%         4,2;...
%         4,3;...
%         5,2;...
%         5,4;];
% edge_weights = [6,3,3,2,1,1,4,2];
data=[];
data2=[];
R = 100;
%% create DAG
V = [10,20,28,40,56];%10,20,28,40,56
n_ver = size(V);

for v = 1:n_ver(2)
    V(v)
    E = [V(v):V(v)*2]; %:V(v)*2
    n_edge = size(E);
    for e = 1:n_edge(2)
        for r = 1:R;
            localR = [];
            A = zeros(V(v),V(v));
            edges = randi([1,V(v)],E(e),2);
            edge_weights = randi([1,50],1,E(e));
            for i = 1:E(e)
                if edges(i,1)== edges(i,2)
                    edge_weights(1,i) = 0;
                end
                A(edges(i,1),edges(i,2)) = edge_weights(1,i);
            end
    %% B-F

            d = MAX_INT*ones(1,V(v));
            d(1,1)=0;   % source is always the first node
            tic            
            for i=1:V(v)
                for j=1:E(e)
                    if (d(edges(j,2)) > d(edges(j,1))+A(edges(j,1),(edges(j,2))))
                    d(edges(j,2)) = d(edges(j,1))+A(edges(j,1),(edges(j,2)));
                    predecessor(edges(j,2)) =edges(j,1);
                    end
                end
            end
            localR = [localR; toc];
        
%        predecessors(e,:) = predecessor;
        end
        data = [data; V(v), E(e), mean(localR)];
        data2 = [data2; V(v)*E(e), mean(localR)];
    end
end
res = sortrows(data2,1);

%plot(data(:,1), data(:,3),'o-r')
%xlabel('Number of vertices, V','FontSize',14);

plot(data(:,2), data(:,3),'or')
%xlabel('Number of edges, E','FontSize',14);
plot (res(:,1), res(:,2),'or')
xlabel('V x E','FontSize',14);
% Create ylabel
ylabel('Run time, (s)','FontSize',14);