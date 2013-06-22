private: System::Void Run_Click(System::Object^  sender, System::EventArgs^  e) 
		 {

				const int MAX_MSG_LENGTH = 4096;
				const int MAX_RMSG_LENGTH = 1024;
				int x = 0, y = 0, i, rcv;
				String ^ msg;

				//server->SendTimeout = 1000;
				//server->ReceiveTimeout = 10000;
				for each(String^ ipAddr in ServerList->Items)
				{
					x = 0;
					y = 0;
	
					OutPutWindow->AppendText("\r\n" + "Processing server at : " + ipAddr);

					try
					{
						Socket^ server = gcnew Socket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp);
						IPEndPoint^ iped = gcnew IPEndPoint(IPAddress::Parse(ipAddr), 23);
						server->Connect(iped);
						server->NoDelay = true;
						array<unsigned char>^ rmsg = gcnew array<unsigned char>(MAX_RMSG_LENGTH);
						array<unsigned char>^ smsg = gcnew array<unsigned char>(MAX_MSG_LENGTH);
						array<unsigned char>^ tempmsg = gcnew array<unsigned char>(MAX_MSG_LENGTH);
						for (i = 0; i < MAX_RMSG_LENGTH; ++i)
							rmsg[i] = 0;
						for (i = 0; i < MAX_MSG_LENGTH; ++i)
							smsg[i] = 0;

						while (true)
						{
							
							rcv = server->Receive(rmsg, MAX_RMSG_LENGTH, SocketFlags::None);
	
							if (Convert::ToByte(255) == rmsg[0])
							{
								
								while (rmsg[x] != 0 && x < MAX_RMSG_LENGTH)
								{
									++x;

									if (Convert::ToByte(253) == rmsg[x])
									{
										++x;
										if (Convert::ToByte(3) == rmsg[x])
										{
											smsg[y] = Convert::ToByte(255);
											++y;
											smsg[y] = Convert::ToByte(251);
											++y;
											smsg[y] = rmsg[x];
											++y;
										}
										else
										{
											smsg[y] = Convert::ToByte(255);
											++y;
											smsg[y] = Convert::ToByte(252);
											++y;
											smsg[y] = rmsg[x];
											++y;
										}
									}
								}

								if (y > 0)
								{
									msg = Encoding::ASCII->GetString(smsg, 0, smsg->Length);
									server->Send(smsg, smsg->Length, SocketFlags::None);
								}

								x = 0;
								y = 0;

								// After the send clean up for next message
								for (i = 0; i < MAX_RMSG_LENGTH; ++i)
									rmsg[i] = 0;
								for (i = 0; i < MAX_MSG_LENGTH; ++i)
									smsg[i] = 0;
								
							}

							else
								break;
						}
						

						msg = Encoding::ASCII->GetString(rmsg, 0, rcv);
						OutPutWindow->AppendText(msg);

						for (i = 0; i < MAX_RMSG_LENGTH; ++i)
							rmsg[i] = 0;
						for (i = 0; i < MAX_MSG_LENGTH; ++i)
							smsg[i] = 0;

						smsg = Encoding::ASCII->GetBytes(User_ID->Text + "\r\n");
						
						server->Send(smsg, smsg->Length, SocketFlags::None);

						while (server->Available == 0);
						rcv = server->Available;
						if (rcv > MAX_RMSG_LENGTH)
							rcv = MAX_RMSG_LENGTH;

						while ( rcv > 0 )
						{
							server->Receive(rmsg, rcv, SocketFlags::None);
							msg = Encoding::ASCII->GetString(rmsg, 0, rcv);
							OutPutWindow->AppendText(msg);
							rcv = server->Available;
							if (rcv > MAX_RMSG_LENGTH)
								rcv = MAX_RMSG_LENGTH;
							for (i = 0; i < MAX_RMSG_LENGTH; ++i)
								rmsg[i] = 0;
						}


						smsg = Encoding::ASCII->GetBytes(Pass_Word->Text + "\r\n");
						
						server->Send(smsg, smsg->Length, SocketFlags::None);


						while (server->Available == 0);
						//Sleep(1);
						rcv = server->Available;
						if (rcv > MAX_RMSG_LENGTH)
							rcv = MAX_RMSG_LENGTH;

						while ( rcv > 0 )
						{
							server->Receive(rmsg, rcv, SocketFlags::Partial);
							msg = Encoding::ASCII->GetString(rmsg, 0, rcv);
							OutPutWindow->AppendText(msg);
							for (i = 0; i < MAX_RMSG_LENGTH; ++i)
								rmsg[i] = 0;
							rcv = server->Available;
							if (rcv > MAX_RMSG_LENGTH)
								rcv = MAX_RMSG_LENGTH;
						}


						smsg = Encoding::ASCII->GetBytes(Command_Line->Text + "\r\n");
						
						server->Send(smsg, smsg->Length, SocketFlags::None);



						while (server->Available == 0);
						//Sleep(1);
						rcv = server->Available;
						if (rcv > MAX_RMSG_LENGTH)
							rcv = MAX_RMSG_LENGTH;

						while ( rcv > 0 )
						{
							server->Receive(rmsg, rcv, SocketFlags::Partial);
							msg = Encoding::ASCII->GetString(rmsg, 0, rcv);
							OutPutWindow->AppendText(msg);
							rcv = server->Available;
							if (rcv > MAX_RMSG_LENGTH)
								rcv = MAX_RMSG_LENGTH;
							for (i = 0; i < MAX_RMSG_LENGTH; ++i)
								rmsg[i] = 0;
						}


						server->Shutdown(SocketShutdown::Both);
						server->Close();
						delete iped;
						delete server;

					}
					catch ( Exception^ e ) 
					{
						OutPutWindow->AppendText("\r\n" + e);
						OutPutWindow->AppendText("\r\nProcess Failed : " + ipAddr);
					}

					catch(...)
					{
						OutPutWindow->AppendText("\r\nUnable to process server : " + ipAddr);
					}
				}
			 }