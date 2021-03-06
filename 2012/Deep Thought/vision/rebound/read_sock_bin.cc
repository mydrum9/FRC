/** 
 * @file  read_sock_bin.cc
 *
 * $Id: $
 *
 * @author  Team 691
 * @date    March 15, 2010
 *
 * Read test for SuperSock class client
 *
 */ 


#include "super_sock.h"
#include "KPacket.h"

using namespace std;
using namespace Team691;


int main(int argc, char const ** argv)
{
  char * port = (char *)"20000";
  char * inet_addr = (char *)"localhost";

  cout << "argc = " << argc << endl;

  SuperSock s;
  if(argc >= 2)
    port = (char *)argv[1];

  if(argc >= 3)
    inet_addr = (char *)argv[2];

  if(s.init(port, inet_addr))
    {
      cout << "Socket initialized" << endl;
    }
  else
    {
      return -1;
    }

  int len = 0;
  //  unsigned char data[1000];

  KPacketOut data;

  for (int i = 0; true; i++)
  {
      
      data.head[0] = 0;

//       int rc = s.read_timeout((unsigned char *)&len, 
//                               sizeof(len), 
//                               100000000);
      s.read_timeout((unsigned char*)&data, sizeof(data), 10000);


      if (data.head[0] == 'H')
      cout << "data.head  = " <<                data.head                 << endl
	       << "data.frame_count = " <<          data.frame_count          << endl
	       << "data.offset_from_top = " <<      data.offset_from_top      << endl
	       << "data.offset_from_left = " <<     data.offset_from_left     << endl
	       << "data.offset_from_right = " <<    data.offset_from_right    << endl
	       << "data.offset_from_bottom = " <<   data.offset_from_bottom   << endl
	       << "data.speed_top = " <<            data.speed_top            << endl
	       << "data.speed_left = " <<           data.speed_left           << endl
	       << "data.speed_right = " <<          data.speed_right          << endl
	       << "data.speed_bottom = " <<         data.speed_bottom         << endl
	       << "data.distance = " <<             data.distance             << endl
	       << "data.angle = " <<                data.angle                << endl
	       << "data.target_number = " <<        data.target_number        << endl;
           
      
      usleep(100);

  }

  return 0;

}
