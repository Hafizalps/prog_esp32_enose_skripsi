float fLimit(float in, float top, float bottom, float ifNan){
  if (!(in==in)){
    return ifNan;
  }
  else if (in<bottom){
    return bottom;
  }
  else if(in>top){
    return top;
  }else
    return in;
}

float sign(float in ){
  if (in<0){
    return -1;
  }
  else
    return 1;
}
