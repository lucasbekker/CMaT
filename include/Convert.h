GPU_Dense convert ( CPU_Dense x ) {

    GPU_Dense y(x.Size[0],x.Size[1],x.isVector);

    y.Values = x.Values;

    return y;

}

GPU_Dense_f convert ( CPU_Dense_f x ) {

    GPU_Dense_f y(x.Size[0],x.Size[1],x.isVector);

    y.Values = x.Values;

    return y;

}

CPU_Dense convert ( GPU_Dense x ) {

    CPU_Dense y(x.Size[0],x.Size[1],x.isVector);

    y.Values = x.Values;

    return y;

}

CPU_Dense_f convert ( GPU_Dense_f x ) {

    CPU_Dense_f y(x.Size[0],x.Size[1],x.isVector);

    y.Values = x.Values;

    return y;

}