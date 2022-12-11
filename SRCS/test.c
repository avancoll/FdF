int color_handler(t_data *data)
{
  int event;
  
  if (data->draw->z0 == 0 && data->draw->z1 == 0)
     event = 0;
  else if (data->draw->z0 >= 0 && data->draw->z0 < data->draw->z1)
    event = 1;
  else if (data->draw->z0 <= 0 && data->draw->z0 > data->draw->z1)
    event = 2;
  
}
