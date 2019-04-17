GPU_Dense convert ( CPU_Dense x ) {

    GPU_Dense y(x.Size[0],x.Size[1],x.isVector);

    y.Values = x.Values;

    return y;

}

CPU_Dense convert ( GPU_Dense x ) {

    CPU_Dense y(x.Size[0],x.Size[1],x.isVector);

    y.Values = x.Values;

    return y;

}